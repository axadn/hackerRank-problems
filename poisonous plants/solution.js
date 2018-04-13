process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}
/////////////// ignore above this line ////////////////////

// pseudocode:
// if stack is empty push number
// if stack is greater than top, push number and (1 day til death)
//     (pop top before pushing if top also dying in 1 day)
// if less than or equal to top, pop numbers until greater than top
//     push number and days until dying
//      (pop top if top dying in same number of days)


function poisonousPlants(p) {
    const stack = [];
    let maxDaysTilDeath = 0;
    let daysTilDeath;
    let top;
    for(let i  = 0; i < p.length ; ++i){
        if(stack.length == 0){
            stack.push([p[i], -1]);
        }
        else if(p[i] > stack[stack.length - 1][0]){
            if(stack[stack.length - 1][1]== 1){
                stack.pop();
            }
            stack.push([p[i], 1]);
            maxDaysTilDeath = Math.max(maxDaysTilDeath, 1);
        }
        else{
            while(stack.length > 1){
                top = stack.pop();
                if(p[i] > stack[stack.length - 1][0]){
                    if(stack[stack.length - 1][1]== top[1] + 1){
                        stack.pop();
                    }
                    stack.push([p[i], top[1] + 1]);
                    maxDaysTilDeath = Math.max(maxDaysTilDeath, top[1] + 1);
                    break;
                }
            }
            if(stack.length == 1){
                stack.pop();
                stack.push([p[i], -1]);
            }
        }
    }
    return maxDaysTilDeath;
}

function main() {
    var n = parseInt(readLine());
    p = readLine().split(' ');
    p = p.map(Number);
    var result = poisonousPlants(p);
    process.stdout.write("" + result + "\n");

}
