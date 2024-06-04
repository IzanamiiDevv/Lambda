using System;

class Program : Lambda
{
    public static void Main(string[] args)
    {
        string[] names = {"Gab", "Rose", "Justine"};
        int[] numbers = {10,2,4,30};
        string text = "I Love You";
        
        ForEach(numbers, (int num)=>{
            Console.WriteLine(num * 2);
            
            return 0;
        });
        
        ForEach(names, (string name)=>{
            
            Console.WriteLine(name);
            return 0;
        });
        
        ForEach(text, (char c)=>{
            
            Console.WriteLine(c);
            return 0;
        });
    }
}

class Lambda
{
    //Array of Int
    public static void ForEach(int[] arr, Func<int,int> callback)
    {
        for(int i = 0; i < arr.Length; i++)
        {
            callback(arr[i]);
        }
    }
    
    //Array of String
    public static void ForEach(string[] arr, Func<string,int> callback)
    {
        for(int i = 0; i < arr.Length; i++)
        {
            callback(arr[i]);
        }
    }
    
    //String
    public static void ForEach(string txt, Func<char,int> callback)
    {
        for(int i = 0; i < txt.Length; i++)
        {
            callback(txt[i]);
        }
    }
}