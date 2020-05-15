
// 获取link标签
var link = document.getElementById('link');

//获取主题切换选项
var theme = document.getElementById('dropdown').getElementsByTagName('li');

//轮播图左右按钮及图
var turn = document.getElementById("lunbo");
var lBtn = document.getElementById("leftBtn");
var rBtn = document.getElementById("rightBtn");

//轮播图对应的点
var point = document.getElementById("circleBox").getElementsByTagName('li');

//轮播图外的容器
var picbox = document.getElementById("picbox");

//轮播图片
var pic = document.getElementById("picbox").getElementsByTagName("img");

//point的长度赋给length
var len = point.length ;

//num对应轮播图
var num = 1;

//对应主题切换
var numb = 1;

//获取登录块
var mylogin = document.getElementById("mylogin");

//用户信息显示地方
var Uname = document.getElementById("Uname");

//用户数据
var u = sessionStorage.getItem("user");
if(u != null) {
    Uname.innerHTML = u;
}
// console.log(u);

if(Uname.innerHTML != "") {
    mylogin.style.visibility = "hidden";
}

// 音乐播放(兼容谷歌)
setInterval (function(){
    //获取音乐
    var music = document.getElementById("music");
    if(music.paused) {
        music.paused = false;
        music.play();
    }
},1);


//主题切换两个页面保证主题一样
var color = sessionStorage.getItem("color");

if(!isNaN(parseInt(color))){
    numb = parseInt(color);
}

link.href = 'css/qgpic' + numb + '.css';

sessionStorage.setItem("color",numb);

//主题切换
for(var i = 0; i < theme.length; i++){
    theme[i].index = i;
    theme[i].onclick = function () {
        numb = this.index + 1;
        link.href = 'css/qgpic' + numb + '.css';
        sessionStorage.setItem("color",numb);
    }
}

/* 轮播图 */

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

//清除class
function clearName(a){
    for(var i = 0,len = a.length; i < len; i++){
        a[i].className = "";
    }
}

//点击对应的图片被显示在中间
pic[0].onclick = function(){
    lBtn.onclick();
}

pic[pic.length - 1].onclick = function(){
    rBtn.onclick();
}

//左右图片的对应序数
function selectX(x, len, num){
    x= num - 1;
    if(x == 0){
        x = len;
    }
    return x;
}

function selectY(y, len, num){
    y = num + 1;
    if(y == len + 1){
        y = 1;
    }
    return y;
}

// 点击左箭头换图
lBtn.onclick = function(){
    var x, y;
    num--;
    if(num == 0){
        num = len;
    }
    x = selectX(x, len, num);
    y = selectY(y, len, num);
    pic[0].src = "images/man" + x + ".jpg";
    turn.src="images/man"+num+".jpg";
    pic[pic.length - 1].src = "images/man" + y + ".jpg";
    clearName(point);
    point[num-1].className = "active";
}

// 点击右箭头换图
rBtn.onclick = function(){
    var x, y;
    num++;
    if(num == len + 1){
        num = 1;
    }
    x = selectX(x, len, num);
    y = selectY(y, len, num);
    pic[0].src = "images/man" + x + ".jpg";
    turn.src="images/man"+num+".jpg";
    pic[pic.length - 1].src = "images/man" + y + ".jpg";
    clearName(point);
    point[num-1].className = "active";
}

//点来切图
for(var i = 0; i < len; i++){
    point[i].index = i;
    point[i].onclick = function(){
        var x, y;
        num = this.index + 1;
        x = selectX(x, len, num);
        y = selectY(y, len, num);
        pic[0].src = "images/man" + x + ".jpg";
        turn.src = "images/man" + num + ".jpg";
        pic[pic.length - 1].src = "images/man" + y + ".jpg";
        clearName(point);
        point[num - 1].className = "active";
    }
}


//鼠标移上去，触发自动切换事件
picbox.onmouseover = stop;
picbox.onmouseout = play;

//自动播放
play();

