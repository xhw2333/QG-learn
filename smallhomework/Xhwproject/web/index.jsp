<%--
  Created by IntelliJ IDEA.
  User: 小浩王
  Date: 2020/4/27
  Time: 18:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
    <script>
      var u = sessionStorage.getItem("user");
      console.log(u);
    </script>
  </head>
  <body>
  <script language="JavaScript">
    function x() {
      var myName = "<%=session.getAttribute("name")%>"
      alert(name);
    }
  </script>
  ${name}

  <br>
  成功登录
  </body>
</html>
