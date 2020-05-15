var passage = document.getElementById("passage");
var lgUsername = document.getElementById('lgUsername');
var lgPassword = document.getElementById('lgPassword');
var lgBtn = document.getElementById('lgBtn');

//不能包含中文
var reg=/^[a-zA-Z0-9_]+$/;

lgUsername.onclick = function () {

    if(lgUsername.value != null || lgUsername.value != ''){
        passage.innerHTML=("");
    }
}



lgPassword.onclick = function () {

    if(lgPassword.value != null || lgPassword.value != ''){
        passage.innerHTML=("");
    }
}

lgUsername.oninput = function() {

    if(lgUsername.value == null || lgUsername.value == "") {
        passage.innerHTML=("请输入用户名!!");
    }  else {
        passage.innerHTML = ("");
    }
}

lgPassword.oninput= function() {

    if(lgPassword.value == null || lgPassword.value == "") {
        passage.innerHTML=("请输入密码!!");
    } else if(!reg.test(lgPassword.value)){
        passage.innerHTML=("密码格式错误(输入数字、英文)!!");
    } else {
        passage.innerHTML = ("");
    }
}

lgBtn.onmouseover = function () {
    if(lgUsername.value == null || lgUsername.value == "") {
        passage.innerHTML=("请输入用户名!!");
    } else if(lgPassword.value == null || lgPassword.value == "") {
        passage.innerHTML=("请输入密码!!");
    }
}
