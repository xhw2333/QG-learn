//获取搜索按钮
var submit = document.getElementById("submit");



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
            //此时这个返回的数据是个字符串，我们需要调用JSON.parse方法把他转成js对象才能够操作\                                                                                                                                               .0
            // var result = JSON.parse(xml_http.responseText);
            //成功对应做成功的业务逻辑，失败对应做失败的业务逻辑
            var result = xml_http.responseText;
            result = eval('(' + result + ')');
                //do something
                console.log(result);
                console.log(typeof (result));
         
        }
    }
}




		// let con = document.getElementsByClassName('con')[0];

		// // 创建ajax请求
		// var http = new XMLHttpRequest();
		// http.onreadystatechange = function() {
		// 	if (http.readyState === 4 && http.status === 200) {
		// 		let result = JSON.parse(http.responseText);
		// 		//console.log(result)
		// 		createDom(result);
        //     }
		// }

		// // 创造节点
		// function createDom(dataList) {
		// 	let htmlStr = ''
		// 	let len = dataList.length;
		// 	for(let i = 0; i < len; i++) {
		// 		htmlStr += getHtmlStr(dataList[i]);
		// 	}
		// 	console.log(htmlStr);
		// 	con.innerHTML = htmlStr;
		// }
		// // 获取模板字符串

		// function getHtmlStr(data) {
		// 	let template = 
		// 	`<div class="list">
		// 		<div>
		// 			<span class="name">id: </span>
		// 			<span class="data">${data.id}</span>
		// 		</div>
		// 		<div>
		// 			<span class="name">userId: </span>
		// 			<span class="data">${data.userId}</span>
		// 		</div>
		// 		<div>
		// 			<span class="name">title: </span>
		// 			<span class="data">${data.title}</span>
		// 		</div>
		// 		<div>
		// 			<span class="name">body: </span>
		// 			<span class="data">${data.body}</span>
		// 		</div>
		// 	</div>`
		// 	return template;
		// }

		// let btn = document.getElementById('btn');
		// let url = "http://jsonplaceholder.typicode.com/posts";
		// btn.onclick = function() {
		// 	http.open('GET', url, true);
		// 	http.send();
		// }


		
		// // btn.onclick=function() {
		// // 	let result = [
		// // 	{
		// // 		"postId": 1,
		// // 		"id": 1,
		// // 		"name": "id labore ex et quam laborum",
		// // 		"email": "Eliseo@gardner.biz",
		// // 		"body": "laudantium enim quasi est quidem magnam voluptate ipsam eos\ntempora quo necessitatibus\ndolor quam autem quasi\nreiciendis et nam sapiente accusantium"
		// // 	},
		// // 	{
		// // 		"postId": 1,
		// // 		"id": 2,
		// // 		"name": "quo vero reiciendis velit similique earum",
		// // 		"email": "Jayne_Kuhic@sydney.com",
		// // 		"body": "est natus enim nihil est dolore omnis voluptatem numquam\net omnis occaecati quod ullam at\nvoluptatem error expedita pariatur\nnihil sint nostrum voluptatem reiciendis et"
		// // 	},
		// // 	]
		// // 	createDom(result);
		// // }


