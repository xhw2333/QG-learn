var passage = document.getElementById("passage");

function mySubmit() {
    var x = document.forms["Form"]["username"].value;
    var y = document.forms["Form"]["password"].value;
    if(x == null || x == "") {
        passage.innerHTML=("请输入用户名！！");
        return false;
    } else if(y == null || y == "") {
        passage.innerHTML=("请输入密码！！");
        return false;
    }
}
