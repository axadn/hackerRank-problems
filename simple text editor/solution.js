function processData(input) {
    stack = [""];
    let i = 0;
    input.split('\n').forEach(line=>{
        if(i == 0){++i;return;}
        params = line.split(' ');
        switch(params[0]){
            case "1":
                stack.push(stack[stack.length - 1] + params[1]);
                break;
            case "2":
                prevStr = stack[stack.length - 1];
                stack.push(prevStr.slice(0,prevStr.length - parseInt(params[1])));
                break;
            case "3":
                console.log(stack[stack.length - 1][parseInt(params[1]) - 1]);
                break;
            case "4":
                stack.pop();
                break;
        }
    });
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
