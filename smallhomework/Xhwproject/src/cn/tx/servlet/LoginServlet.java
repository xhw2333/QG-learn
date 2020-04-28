package cn.tx.servlet;

import cn.tx.dao.UserDao;
import cn.tx.model.Ueser;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {


    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        //获取到用户输入的用户名和密码
        //用户名
        String username = req.getParameter("username");
        //密码
        String password = req.getParameter("password");

//        System.out.println(username + ":" + password);
        //通过用户名和密码查数据库
        Ueser user = new Ueser();
        int num = UserDao.check(username,password);
        //对num判断
        if(num == 1){
            //登陆成功，
            req.getRequestDispatcher("index.jsp").forward(req,resp);

        } else {
            System.out.println("ERROR");

            req.setAttribute("errorMsg","用户名或密码错误");
            //失败,跳登录页面
            req.getRequestDispatcher("login.html").forward(req,resp);
//            resp.getWriter().write("<script>alert('用户名或密码错误');</script>");
        }

    }
}
