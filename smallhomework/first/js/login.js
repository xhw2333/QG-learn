function mySubmit() {
    var x = document.forms["Form"]["username"].value;
    var y = document.forms["Form"]["password"].value;
    if((x == null || x == "") || (y == null || y == "")) {
        // alert("无效！！");
        if(x == null || x == "") {
            alert("请输入用户名！！");
        }
        if(y == null || y == "") {
            alert("请输入密码！！");
        }
        return false;
    }
    alert("正在登录.....");
}

function myRegister() {
    var a = document.forms["Form"]["username"].value;
    var b = document.forms["Form"]["password"].value; 
    var c = document.forms["Form"]["password2"].value;
    if((a == null || a == "") || (b == null || b == "") || (c == null || c == "")) {
        // alert("无效！！");
        if(a == null || a == "") {
            alert("请输入用户名！！");
        }
        if(b == null || b == "" || c == null || c == "") {
            alert("请输入密码！！");
        }
        // if(b != c){
        //     alert("请确保密码一致");
        // }
        return false;
    }
    if(b != c){
        alert("请确保密码一致");
        return false;
    }
    alert("注册成功");
}