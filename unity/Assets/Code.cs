using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;

public class Code : MonoBehaviour
{
    void Start()
    {
        
    }

    IEnumerator get(string uri)
    {
        UnityWebRequest uwr = UnityWebRequest.Get(uri);
        yield return uwr.SendWebRequest();

        if (uwr.isNetworkError)
        {
            print("Error While Sending: " + uwr.error);
        }
        else
        {
            print("Received: " + uwr.downloadHandler.text);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void Forward(){
        StartCoroutine(get("http://192.168.191.156/F"));
    }

    public void Backward(){
        StartCoroutine(get("http://192.168.191.156/B"));
    }

    public void Left(){
        StartCoroutine(get("http://192.168.191.156/L"));
    }

    public void Right(){
        StartCoroutine(get("http://192.168.191.156/R"));
    }
}
