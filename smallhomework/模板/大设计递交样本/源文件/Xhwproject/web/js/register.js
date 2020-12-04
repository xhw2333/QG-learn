var passage = document.getElementById("passage");
var reUsername = document.getElementById('reUsername');
var rePassword = document.getElementById('rePassword');
var rePhone = document.getElementById('rePhone');


reUsername.onclick = function () {

    if(reUsername.value != null || reUsername.value != ''){
        passage.innerHTML=("");
    }
}

rePassword.onclick = function () {

    if(rePassword.value != null || rePassword.value != ''){
        passage.innerHTML=("");
    }
}

rePhone.onclick = function () {

    if(rePhone.value != null || rePhone.value != ''){
        passage.innerHTML=("");
    }
}

function myRegister() {
    var a = document.forms["Form"]["username"].value;
    var b = document.forms["Form"]["password"].value;
    var c = document.forms["Form"]["phone"].value;
    // 字母加数字
    var reg = /^[a-zA-Z0-9_]+$/;
    //  不能包含中文  /^[\u0391-\uFFE5]+$/
    //电话号码(11位数以1开头)
    var reg2 = /^1[0-9]{10}$/;
    if(a == null || a == "") {
        passage.innerHTML=("请输入用户名！！");
        return false;
    } else if(b == null || b == "") {
        passage.innerHTML=("请输入密码！！");
        return false;
    } else if(!reg.test(b)){
        passage.innerHTML=("密码格式错误(输入数字、英文)!!");
        return false;
    } else if(c == null || c == "") {
        passage.innerHTML=("请输入电话号码！！");
        return false;
    } else if(!reg2.test(c)){
        passage.innerHTML=("电话格式错误");
        return false;
    }
    else {
        alert("注册成功");
    }
}