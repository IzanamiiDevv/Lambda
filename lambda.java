interface Lambda {
    void run(int data);
}

class HelloWorld {
    public static void main(String[] args) {
        int[] numbers = {10,20,33,45};
        System.out.println("Hello World");
        
        forEach(numbers,(int number)->{
            System.out.println(number);
        });
    }
    
    public static void forEach(int[] arr,Lambda fn) {
        for(int i = 0; i < arr.length; i++){
            fn.run(arr[i]);
        }
    }
}