package cn.tx.servlet;

import cn.tx.dao.UserDao;
import cn.tx.model.Ueser;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.text.SimpleDateFormat;


//等会吻合便行
@WebServlet("/regist")
public class RegisterServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //接收注册的一些name
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String phone = req.getParameter("phone");


//        System.out.println(username + " " + password);
        //字符串转换成java.util.Date
//        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM--dd");
//        Date date = format.parse(birth);

        Ueser user = new Ueser();
        user.setUsername(username);
        user.setPassword(password);
        user.setPhone(phone);

        UserDao.insert(user);

        resp.sendRedirect("login.html");
    }
}
