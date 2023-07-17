const prompt = require("prompt-sync")();
    var n =prompt("enter the values:")
    var copy;
    var remainder;
    var revrese=0;
    
    n=copy;
    while(n!==0){
        remainder=n%10;
        revrese=revrese*10+remainder;
        n=n/10;

        
    }
    if(revrese===copy)
{
    console.log("it is polindrome"+copy+"number");
}    
    else{
        console.log("it is not  polindrome"+copy+"number");
    }