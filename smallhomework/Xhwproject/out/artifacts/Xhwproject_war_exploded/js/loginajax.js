

var lgBtn = document.getElementById('lgBtn');

lgBtn.onclick = function () {
    
    var username = document.getElementById('lgUsername').value;
    var password = document.getElementById('lgPassword').value;

    //建立请求对象实例
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("POST","login",true);
    //设置请求头
    xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
    //post方法发送数据，如果是get方法可以不用写send的参数
    xmlhttp.send("username="+username+"&password="+password);
    //onreadystatechange相当于一个事件，当服务器有响应的时候就会触发这个方法
    xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
            //此时这个返回的数据是个字符串，我们需要调用JSON.parse方法把他转成js对象才能够操作\                                                                                                                                               .0
            var result = xmlhttp.responseText;
            //成功对应做成功的业务逻辑，失败对应做失败的业务逻辑
            if(result == 1){
                document.getElementById("passage").innerHTML = "用户名或密码错误";
                // alert("用户名或密码错误");
            }else {
                sessionStorage.setItem("user",result);
                window.location = "qgspace.html";
                // alert(result);
                // document.getElementById("passage").innerHTML = result;
            }
        }
    }
}