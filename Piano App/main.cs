using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;  
using System.IO.Ports;  
using System.Threading;  
public class main : MonoBehaviour
{
    SerialPort _serialPort = new SerialPort("COM2", 9600, Parity.None, 8, StopBits.One);  
    // Start is called before the first frame update
    void Start()
    {
        
        _serialPort.Handshake = Handshake.None;   
        _serialPort.Open();   

    }

    // Update is called once per frame
    void Update()
    {
            //get the input
    var input = Input.inputString;

    //ignore null input to avoid unnecessary computation
    if (!string.IsNullOrEmpty(input))
    {
        try  
        {  
            if(!(_serialPort.IsOpen))  
            _serialPort.Open();  
            _serialPort.Write(input);  
        }  
        catch (Exception ex)  
        {  
            
        }  
    }
    }
    
   public void send(string ip)
    {
       try  
        {  
            if(!(_serialPort.IsOpen))  
            _serialPort.Open();  
            _serialPort.Write(ip);  
        }  
        catch (Exception ex)  
        {  
            
        }  
    }
}

