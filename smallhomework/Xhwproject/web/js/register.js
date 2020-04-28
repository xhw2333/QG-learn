var passage = document.getElementById("passage");

function myRegister() {
    var a = document.forms["Form"]["username"].value;
    var b = document.forms["Form"]["password"].value;
    var c = document.forms["Form"]["phone"].value;
    if(a == null || a == "") {
        passage.innerHTML=("请输入用户名！！");
        return false;
    } else if(b == null || b == "") {
        passage.innerHTML=("请输入密码！！");
        return false;
    }else if(c == null || c == "") {
        passage.innerHTML=("请输入电话号码！！");
        return false;
    }else if(c.length != 11 && c.length != 3){
        passage.innerHTML=("电话格式错误");
        return false;
    }
    else {
        alert("注册成功");
    }
}