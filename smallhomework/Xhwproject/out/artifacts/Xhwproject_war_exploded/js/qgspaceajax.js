//获取搜索按钮
var submit = document.getElementById("submit");

//获取插入地方
var palace = document.getElementById("Content");

//获取标题
var Sum = document.getElementById("Sum");

//获取日志提交按钮
var send = document.getElementById("send");


submit.onclick = function () {
    
    var key = document.getElementById('search').value;

    //建立请求对象实例
    var xml_http = new XMLHttpRequest();
    xml_http.open("POST", "search", true);
    //设置请求头
    xml_http.setRequestHeader("Content-type","application/x-www-form-urlencoded");
    //post方法发送数据，如果是get方法可以不用写send的参数
    xml_http.send("key=" + key);
    //onreadystatechange相当于一个事件，当服务器有响应的时候就会触发这个方法
    xml_http.onreadystatechange = function() {
        if (xml_http.readyState === 4 && xml_http.status === 200) {
            //成功对应做成功的业务逻辑，失败对应做失败的业务逻辑
            var result = xml_http.responseText;
            result = eval('(' + result + ')');
            //判断传回来的是什么值
            if(result instanceof Array){
                createDom(result);
                // createDom(result);
            } else if (result instanceof Object) {
                palace.innerHTML = getHTML(result);
                // console.log(2);
            } else {
                palace.innerHTML = "无结果";
            }
        }
    }
}

/*
send.onclick = function () {

    var data = {
        title: document.getElementById('title').value,
        date: document.getElementById('date').value,
        tab: document.getElementById('tab').value,
        text:document.getElementById('text').value
    }

    //建立请求对象实例
    var http = new XMLHttpRequest();
    http.open("POST", "add", true);
    //设置请求头
    http.setRequestHeader("Content-type","application/json");
    //post方法发送数据，如果是get方法可以不用写send的参数
    http.send(JSON.stringify(data));
    //onreadystatechange相当于一个事件，当服务器有响应的时候就会触发这个方法
    http.onreadystatechange = function() {
        // if (http.readyState === 4 && http.status === 200) {
        //     //成功对应做成功的业务逻辑，失败对应做失败的业务逻辑
        //     var result = JSON.parse(http.responseText);
        //     //判断传回来的是什么值
        //     if(result instanceof Array){
        //         createDom(result);
        //         // createDom(result);
        //     } else if (result instanceof Object) {
        //         palace.innerHTML = getHTML(result);
        //         // console.log(2);
        //     } else {
        //         palace.innerHTML = "无结果";
        //     }
        // }
    }
}
*/

function  createDom(datalist) {
    var htmlStr = '';
    var len = datalist.length;
    for(var i = 0; i < len; i++){
        htmlStr += getHTML(datalist[i]);
    }
    //获取那个区域，插入
    palace.innerHTML = htmlStr;
}


function getHTML(data) {
    //${}字符串拼接
    var template =
        `<li>
            <h5>${data.title}
                <span>${data.tab}</span>
            </h5>
            <i>${data.date}</i>
            <div>
                  ${data.text}
            </div>
            <ol class="clearfix">
                <li class="iconfont fl">&#xe506;</li>
                <li class="iconfont fl">&#xe602;</li>
                <li class="iconfont fl">&#xe65b;</li>
            </ol>
        </li>`
    return template;
}




