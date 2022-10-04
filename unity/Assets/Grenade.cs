using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;

public class Grenade : MonoBehaviour
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
        StartCoroutine(get("http://localhost:3001/direction?direction=F"));
    }

    public void Backward(){
        StartCoroutine(get("http://localhost:3001/direction?direction=B"));
    }
}
