#region my
///documentation:
///Client API reference: https://docs.aws.amazon.com/gamelift/latest/developerguide/realtime-sdk-csharp-ref-actions.html
///realtime servers interface reference: https://docs.aws.amazon.com/gamelift/latest/developerguide/realtime-script-objects.html
///realtime server callbacks reference: https://docs.aws.amazon.com/gamelift/latest/developerguide/realtime-script-callbacks.html
///Original realTimeServerScript.js from Amazon: https://docs.aws.amazon.com/gamelift/latest/developerguide/realtime-script.html
#endregion

using System;
using System.Text;
using Aws.GameLift.Realtime;
using Aws.GameLift.Realtime.Event;
using Aws.GameLift.Realtime.Types;
using Newtonsoft.Json.Linq;
using UnityEngine;

public class Payload
{
    public string payload;

    public Payload(string payload)
    {
        this.payload = payload;
    }
}

public class RealTimeClient
{
    public Aws.GameLift.Realtime.Client Client { get; private set; }

    #region test OPCode
    // An opcode defined by client and your server script that represents a custom message type
    private const int MY_TEST_OP_CODE = 10;
    #endregion

    /// Initialize a client for GameLift Realtime and connect to a player session.
    /// <param name="endpoint">The DNS name that is assigned to Realtime server</param>
    /// <param name="remoteTcpPort">A TCP port for the Realtime server</param>
    /// <param name="listeningUdpPort">A local port for listening to UDP traffic</param>
    /// <param name="connectionType">Type of connection to establish between client and the Realtime server</param>
    /// <param name="playerSessionId">The player session ID that is assigned to the game client for a game session </param>
    /// <param name="connectionPayload">Developer-defined data to be used during client connection, such as for player authentication</param>
    public RealTimeClient(string endpoint, int remoteTcpPort, int listeningUdpPort, ConnectionType connectionType,
                 string playerSessionId, byte[] connectionPayload)
    {
    // Create a client configuration to specify a secure or unsecure connection type
    // Best practice is to set up a secure connection using the connection type RT_OVER_WSS_DTLS_TLS12.
    ClientConfiguration clientConfiguration = new ClientConfiguration()
        {
            // C# notation to set the field ConnectionType in the new instance of ClientConfiguration
            ConnectionType = connectionType
        };

        // Create a Realtime client with the client configuration            
        Client = new Client(clientConfiguration);

        // Initialize event handlers for the Realtime client
        Client.ConnectionOpen += new EventHandler(OnOpenEvent);
        Client.ConnectionClose += new EventHandler(OnCloseEvent);
        Client.DataReceived += new EventHandler<DataReceivedEventArgs>(OnDataReceived);
        Client.ConnectionError += new EventHandler<Aws.GameLift.Realtime.Event.ErrorEventArgs>(OnConnectionErrorEvent);

        // Create a connection token to authenticate the client with the Realtime server
        // Player session IDs can be retrieved using AWS SDK for GameLift
        ConnectionToken connectionToken = new ConnectionToken(playerSessionId, connectionPayload);

        // Initiate a connection with the Realtime server with the given connection information
        Client.Connect(endpoint, remoteTcpPort, listeningUdpPort, connectionToken);
        activateListeners();
        Debug.Log("RTC instantiated");
    }

    private void OnConnectionErrorEvent(object sender, ErrorEventArgs e)
    {
        Debug.Log("on connection error");
    }

    private void activateListeners()
    {
        //Event listeners
        EventManager.PlayerReady.AddListener(playerReady); //i am ready
        EventManager.playAgain.AddListener(playAgain);
        EventManager.Move.AddListener(myMove); //my move
    }
    private void playAgain()
    {
        //opcode: 5
        //payload: none
        Payload payload = new Payload("");
        SendStringToServer(5, payload);
    }
    private void playerReady()
    {
        //opcode 10
        //payload: none
        Payload payload = new Payload( "");
        SendStringToServer(10, payload);
    }
    private void myMove(MoveEventData data)
    {
        //opcode 30
        //move: X (e.g. “L1”, “R4”,…)
        Payload payload = new Payload(data.row.ToString() + data.slot.ToString());
        SendStringToServer(30, payload);
    }

    public void Disconnect()
    {
        if (Client.Connected)
        {
            Client.Disconnect();
        }
    }

    public bool IsConnected()
    {
        return Client.Connected;
    }

    /// <summary>
    /// Example of sending to a custom message to the server.
    /// 
    /// Server could be replaced by known peer Id etc.
    /// </summary>
    /// <param name="intent">Choice of delivery intent ie Reliable, Fast etc. </param>
    /// <param name="payload">Custom payload to send with message</param>

    //standard message
    /*public void SendMessage(DeliveryIntent intent, string payload)
    {
        Client.SendMessage(Client.NewMessage(MY_TEST_OP_CODE)
            .WithDeliveryIntent(intent)
            .WithTargetPlayer(Constants.PLAYER_ID_SERVER)
            .WithPayload(StringToBytes(payload)));
    }*/

    public void SendStringToServer(int opCode, Payload payload)
    {
        
        string json = JsonUtility.ToJson(payload);

        Client.SendMessage(Client.NewMessage(opCode)
            .WithDeliveryIntent(new DeliveryIntent())
            .WithPayload(StringToBytes(json)));
        Debug.Log("Message sent: " + opCode + " " + json);
    }

    public virtual void OnDataReceived(object sender, DataReceivedEventArgs e)
    {
        // handle message based on OpCode
        #region M3 OPCODES
        /*{
                   "board":
                   [
                       [1,2,3,4,5],
                       [1,2,3,4,5],
                       [1,2,3,4,5],
                       [1,2,3,4,5],
                       [1,2,3,4,5]
                   ],
                   "wheel": [1,2,3],

                   "player": "player1ID"
               }*/

        #region Event Opcodes
        /*
        // Networking (opcode at the end)
        public static PlayerAcceptedEvent PlayerAccepted = new PlayerAcceptedEvent();           //1
        public static DisconnectEvent Disconect = new DisconnectEvent();                        //2
        public static PlayAgainEvent playAgain = new PlayAgainEvent();                          //5 sender: Player
        public static OpponentPlayAgainEvent OponentPlayAgain = new OpponentPlayAgainEvent();   //5
        public static PlayerReadyEvent PlayerReady = new PlayerReadyEvent();                    //10 sender: Player
        public static BoardConfigEvent BoardConfig = new BoardConfigEvent();                    //11
        public static PlayerHasTurn PlayerHasTurn = new PlayerHasTurn();                        //20
        public static MoveEvent Move = new MoveEvent();                                         //30 sender: Player
        public static OpponentMoveEvent OpponentMove = new OpponentMoveEvent();                 //30
        public static GameOverEvent GameOver = new GameOverEvent();                             //40
        public static OpponentDisconnectEvent OpponentDisconect = new OpponentDisconnectEvent();//300
        public static InvalidRequestEvent InvalidRequest = new InvalidRequestEvent();           //311
        public static InvalidMoveEvent InvalidMove = new InvalidMoveEvent();                    //320
        */
        #endregion

        #region Server Opcodes
        /*
        Sender: Server ->accepted player                //1
        Sender: Server ->acknowledge player disconnect  //2
        Sender: player ->player wants to play again     //5
        Sender: Server ->opponent wants to play again   //5
        Sender: Server ->opponent left please leave     //300
        */

        #endregion

        #endregion
        string result = BytesToString(e.Data);
        Debug.Log("On Data Received "+result);
        Debug.Log("Opcode " + e.OpCode);
        JObject json = new JObject();
        try
        {
            json = JObject.Parse(result);

        }catch(Exception)
        {
            Debug.Log("json creation error");
        }
        
        string playerID;
        string message;

        switch (e.OpCode)
        {
            case 1:  //player has been accepted
                EventManager.PlayerAccepted.Invoke(result);
                break;
            case 2:  //player has disconnected
                EventManager.Disconect.Invoke(result);
                break;
            case 5:  //opponent wants to play again
                EventManager.OponentPlayAgain.Invoke();
                break;
            case 10: //both players connected
                Payload payload = new Payload("");
                SendStringToServer(10, payload);
                //playerID = JObject.Parse(result)["playerId"].ToString();
                /*GameManager.Instance.Me.SetPlayerID(playerID);
                EventManager.PlayerReady.Invoke();*/
                break;
            case 11: //both players ready
                Debug.Log("boardConfig received");
                boardConfig(result);
                break;
            case 20: //player x has turn
                playerID = JObject.Parse(result)["playerId"].ToString();
                if (playerID == GameManager.Instance.Me.GetPlayerID())
                {
                    EventManager.PlayerHasTurn.Invoke(GameManager.Instance.Me);
                }
                else EventManager.PlayerHasTurn.Invoke(GameManager.Instance.Opponent);
                break;
            case 30: //its my turn
                //prevMove: X (e.g. “L1”) newCard: Y (numbers 0 - 6)
                //lo-ol
                string prevMove = json["prevMove"].ToString();
                BoardEnums.Slot slot = (BoardEnums.Slot)prevMove[1];
                BoardEnums.Row row = (BoardEnums.Row)Int32.Parse(prevMove.Substring(0, 1));
                ItemEnums.Item item = Item.GetItem((int)json["newCard"]);
                EventManager.OpponentMove.Invoke(new OpponentMoveEventData(row, slot, item));
                break;
            case 40: //game ends
                playerID = JObject.Parse(result)["playerId"].ToString();
                if (playerID == GameManager.Instance.Me.GetPlayerID())
                {
                    EventManager.GameOver.Invoke(GameManager.Instance.Me);
                }
                else EventManager.GameOver.Invoke(GameManager.Instance.Opponent);
                break;
            case 300: //opponent disconnected please leave session
                message = JObject.Parse(result)["error"].ToString();
                EventManager.Disconect.Invoke(message);
                break;
            case 311: //player didnt send the correct data
                message = JObject.Parse(result)["error"].ToString();
                EventManager.InvalidRequest.Invoke(message);
                break;
            case 320: //turn was incorrect(game rules)
                message = JObject.Parse(result)["error"].ToString();
                EventManager.InvalidMove.Invoke(message);
                break;
            default:
                Debug.Log("Default case in switchCase");
                break;
        }
        Debug.Log("outside switchcase");
    }
    private void boardConfig(String result) //OPCODE 11
    {
        /*
        Die Response des Boards ist ein 2D Array, das ist richtig. War nicht meine Idee, das so wie in der Doku festzuhalten. Hier ein Beispiel wie die Nachricht aussieht:
        {opCode: 11, payload: "{"board":[[5,0,6,1,2],[5,1,2,4,0],[3,3,1,5,3],[5,2,2,4,1],[2,1,6,2,4]],"wheel":[6,5,6]}"}
        */
        //nach .Parse(result) mit selectToken probieren falls errors entstehen
        int[,] boardArr = JObject.Parse(result)["board"]?.ToObject<int[,]>();
        int[] wheelArr = JObject.Parse(result)["wheel"]?.ToObject<int[]>();

        ItemEnums.Item[,] boardArray = new ItemEnums.Item[5, 5];
        ItemEnums.Item[] wheelArray = new ItemEnums.Item[wheelArr.Length];

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                boardArray[i, j] = Item.GetItem(boardArr[i, j]);
            }
        }
        for (int i = 0; i < wheelArr.Length; i++)
        {
            wheelArray[i] = Item.GetItem(wheelArr[i]);
        }

        EventManager.BoardConfig.Invoke(new BoardConfigEventData(boardArray, wheelArray));
    }

    #region connection open event
    /**
     * Handle connection open events
     */
    public void OnOpenEvent(object sender, EventArgs e)
    {
        Debug.Log("On Open Event");
    }
    #endregion

    #region connection close event
    /**
     * Handle connection close events
     */
    public void OnCloseEvent(object sender, EventArgs e)
    {

    }
    #endregion

    #region OnGropuMembershipUpdate
    /**
     * Handle Group membership update events 
     */
    public void OnGroupMembershipUpdate(object sender, GroupMembershipEventArgs e)
    {
    }
    #endregion OnGropuMembershipUpdate
    
    public static byte[] StringToBytes(string str)
    {
        return Encoding.UTF8.GetBytes(str);
    }
    public static string BytesToString(byte[] bytes)
    {
        return Encoding.UTF8.GetString(bytes);
    }
}