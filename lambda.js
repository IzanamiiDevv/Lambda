const names = ["Kyle","Justine","Lian"];
const name = "Mhai";
const numbers = [10,29,12,14,6];

//Array of String
forEach(names, (name)=>{
    console.log(name);
});

//String
forEach(name, (char)=>{
    console.log(char);
});

//Array of Numbers
forEach(numbers, (num)=>{
    console.log(num);
});

function forEach(data, callback){
    for(let i = 0; i < data.length; i++){
        callback(data[i]);
    }
}