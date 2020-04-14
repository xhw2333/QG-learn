
let serverUrl = 'http://recruit.qgailab.com/'

let reBtn = document.getElementById('reBtn')






reBtn.onclick = function () {
    let data = {
        username: document.getElementById('reUsername').value,
        password: document.getElementById('rePassword').value,
        phone: document.getElementById('rePhone').value,
        email: document.getElementById('reEmail').value,
        name: document.getElementById('reName').value
    }
    //建立请求对象实例
    let http = new XMLHttpRequest()
    http.open("POST",serverUrl + "ajax/register", true);
    //设置请求头
    http.setRequestHeader("Content-type","application/json");
    //post方法发送数据，如果是get方法可以不用写send的参数
    http.send(JSON.stringify(data));
    //onreadystatechange相当于一个事件，当服务器有响应的时候就会触发这个方法
    http.onreadystatechange = function() {
        if (http.readyState === 4 && http.status === 200) {
            //此时这个返回的数据是个字符串，我们需要调用JSON.parse方法把他转成js对象才能够操作
            let result = JSON.parse(http.responseText)
            //成功对应做成功的业务逻辑，失败对应做失败的业务逻辑
            if (result.code === 1) {
                //do something
                alert(result.message)
            } else {
                alert(result.message)
            }
        }
    }
}

