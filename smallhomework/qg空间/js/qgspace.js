var turn = document.getElementById("lunbo");
var lBtn = document.getElementById("leftBtn");
var rBtn = document.getElementById("rightBtn");
var point = document.getElementById("circleBox").getElementsByTagName('li');
var record = document.getElementById("record");
//定时器
var timer;

var count ,num;

//point的长度给length
var length = point.length ;


//num对应轮播图
count = 0;
num = 1;

// 时间
setInterval(function() {
    document.getElementById("time").innerHTML = new Date().toLocaleTimeString();
},1000);

record.onclick = function() {
    count++;
    document.getElementById("pane").innerHTML = count;
}

// 自动播放
function play() {
    timer = setInterval(function(){
        rBtn.onclick();
    },3000);
}

//停止播放
function stop() {
    clearInterval(timer);
}

// 点击左箭头换图
lBtn.onclick = function(){
    num--;
    if(num == 0){
        num = length;
    }
    turn.src= "images/man" + num + ".jpg";
    checkButton();
    point[num-1].className = "active";
}

// 点击右箭头换图
rBtn.onclick = function(){
    num++;
    if(num == length + 1){
        num = 1;
    }
    turn.src="images/man"+num+".jpg";
    checkButton();
    point[num-1].className = "active";
}

//点来切图
for(var i = 0; i < length; i++){
    point[i].index = i;
    point[i].onclick = function(){
        num = this.index + 1;
        turn.src = "images/man" + num + ".jpg";
        checkButton();
        point[num - 1].className = "active";
    }
}

//让active没有
function checkButton(){
    for(var i = 0; i < length; i++){
        if(point[i].className == "active"){
            point[i].className = "";
            break;
        }
    }
}
 
//鼠标移上去，触发自动切换事件
lunbo.onmouseover = stop;
lunbo.onmouseout = play;

//自动播放
play();