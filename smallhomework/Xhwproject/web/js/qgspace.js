
//轮播图左右按钮及图
var turn = document.getElementById("lunbo");
var lBtn = document.getElementById("leftBtn");
var rBtn = document.getElementById("rightBtn");

//轮播图对应的点
var point = document.getElementById("circleBox").getElementsByTagName('li');

//获取签到按钮
var record = document.getElementById("record");

//获取公告栏
var notice = document.getElementById("notice").getElementsByTagName("ol");
//获取公告栏的上部分
var tips = document.getElementById("tips").getElementsByTagName("li");

//获取好友列表那的按钮及页面
var page = document.getElementById("Friend").getElementsByTagName("ol");
var lBtn2 = document.getElementById("lBtn");
var rBtn2 = document.getElementById("rBtn");

// //获取body
var body = document.getElementsByTagName("body");

//获取个人日志的每个按钮
var show = document.getElementById("all").getElementsByTagName("em");

//获取个人日志的内容
var diary = document.getElementById("all").getElementsByTagName("ul");


//接收时间返回的值
var timer;

//point的长度赋给length
var length = point.length ;

//对应签到次数
var count = 0;

//num对应轮播图
var num = 1;

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



// 时间显示
setInterval(function() {
    document.getElementById("time").innerHTML = new Date().toLocaleTimeString();
},1000);


//签到次数
record.onclick = function() {
    count++;
    document.getElementById("pane").innerHTML = count;
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

// 点击左箭头换图
lBtn.onclick = function(){
    num--;
    if(num == 0){
        num = length;
    }
    turn.src= "images/man" + num + ".jpg";
    clearName(point);
    point[num-1].className = "active";
}

// 点击右箭头换图
rBtn.onclick = function(){
    num++;
    if(num == length + 1){
        num = 1;
    }
    turn.src="images/man"+num+".jpg";
    clearName(point);
    point[num-1].className = "active";
}

//点来切图
for(var i = 0; i < length; i++){
    point[i].index = i;
    point[i].onclick = function(){
        num = this.index + 1;
        turn.src = "images/man" + num + ".jpg";
        clearName(point);
        point[num - 1].className = "active";
    }
}
 
//鼠标移上去，触发自动切换事件
lunbo.onmouseover = stop;
lunbo.onmouseout = play;

//自动播放
play();

/* */


//公告栏标签页切换

for(var i = 0,len = tips.length; i < len; i++){
    tips[i].index = i;
    tips[i].onclick = function(){
        clearName(tips);
        clearName(notice);
        this.className = "special";
        notice[this.index].className = "content";
        
    }
}



//点击好友列表的左按钮
lBtn2.onclick = function(){
    lBtn2.className += " shaded";
    rBtn2.className = "iconfont";
    clearName(page);
    page[page.length - 1].className = "disappear";
}

//点击好友列表的右按钮
rBtn2.onclick = function(){
    rBtn2.className += " shaded";
    lBtn2.className = "iconfont";
    clearName(page);
    page[0].className = "disappear";
}

//展开和收起日志
for(var i = 0, len = show.length; i < len; i++){
    show[i].index = i;
    show[i].onclick = function(){
        if(this.innerHTML == "展开"){
            diary[this.index].style.display = "block";
            this.innerHTML = "收起";
        } else {
            diary[this.index].style.display = "none";
            this.innerHTML = "展开";
        }
    }
}


// 懒加载
window.onload = function(){
    // 获取图片列表，即img标签列表
    var imgs = document.querySelectorAll('img');



    // 获取到浏览器顶部的距离
    function getTop(e){
        return e.offsetTop;
    }

    // 懒加载实现
    function lazyload(imgs){
        // 可视区域高度
        var h = window.innerHeight;
        //滚动区域高度
        var s = document.documentElement.scrollTop || document.body.scrollTop;
        for(var i = 0;i < imgs.length; i++){

            //图片距离顶部的距离大于可视区域和滚动区域之和时懒加载
            if ((h + s) > getTop(imgs[i])) {
                // 1秒后执行
                (function(i){
                    setTimeout(function(){
                        //判断是否已加载
                        // if(imgs[i].src == null ) {
                            // 隐形加载图片或其他资源，
                            //创建一个临时图片，这个图片在内存中不会到页面上去。实现隐形加载
                            var temp = new Image();
                            //只会请求一次
                            temp.src = imgs[i].getAttribute('data-src');
                            // onload判断图片加载完毕，真是图片加载完毕，再赋值给dom节点
                            temp.onload = function () {
                                //适配轮播图

                                // 获取自定义属性data-src，用真图片替换假图片
                                imgs[i].src = imgs[i].getAttribute('data-src');
                            }
                        // }
                    },1000)
                })(i)
            }
        }
    }
    lazyload(imgs);

    // 滚屏函数
    window.onscroll =function(){
        lazyload(imgs);
        //防止轮播图与点出现不对应
        num = 1;
        clearName(point);
        point[num-1].className = "active";
    }
}










