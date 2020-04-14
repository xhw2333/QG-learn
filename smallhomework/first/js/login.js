function mySubmit() {
    var x = document.forms["Form"]["username"].value;
    var y = document.forms["Form"]["password"].value;
    if(x == null || x == "") {
        alert("请输入用户名！！");
        return false;
    } else if(y == null || y == "") {
        alert("请输入密码！！");
        return false;
    } else {
        alert("SUCCESS");
    }
}

function myRegister() {
    var a = document.forms["Form"]["username"].value;
    var b = document.forms["Form"]["password"].value; 
    var c = document.forms["Form"]["phone"].value;
    var d = document.forms["Form"]["email"].value;
    var e = document.forms["Form"]["name"].value;
    if(a == null || a == "") {
        alert("请输入用户名！！");
        return false;
    } else if(b == null || b == "") {
        alert("请输入密码！！");
        return false;
    } else if(c == null || c == "") {
        alert("请输入电话号码！！");
        return false;
    } else if(d == null || d == "") {
        alert("请输入邮箱！！");
        return false;
    } else if(e == null || e == "") {
        alert("请输入名字！！");
        return false;
    } else {
        alert("注册成功");
    }
}