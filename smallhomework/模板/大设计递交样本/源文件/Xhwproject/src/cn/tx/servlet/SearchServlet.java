package cn.tx.servlet;

import cn.tx.dao.DiaryDao;
import cn.tx.model.Diary;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

@WebServlet("/search")
public class SearchServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        req.setCharacterEncoding("utf-8");
        resp.setContentType("text/html;charset=utf-8");
        PrintWriter out = resp.getWriter();


        String key = req.getParameter("key");
//        System.out.println(key);

        Diary diary = new Diary();
        List<Diary> list = new ArrayList<Diary>();
        diary = DiaryDao.mysearch(key);
        System.out.println(diary);
        list = DiaryDao.myprint(key);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
        if(diary != null){
//            System.out.println("1");
            out.println(diary);
            out.flush();
            out.close();
        } else if(list != null && !list.isEmpty()){
//            System.out.println("2");
            out.println(list);
            out.flush();
            out.close();
        } else {
            out.println("1");
            out.flush();
            out.close();
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

    }
}
