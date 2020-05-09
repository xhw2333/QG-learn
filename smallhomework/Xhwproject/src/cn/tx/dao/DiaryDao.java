package cn.tx.dao;

import cn.tx.model.Diary;
import jdk.nashorn.internal.objects.NativeJSON;

import java.sql.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

public class DiaryDao {


        private static final String driver = "com.mysql.cj.jdbc.Driver";
        private static final String url = "jdbc:mysql://localhost:3306/myku?characterEncoding=utf-8&serverTimezone=GMT%2B8";
        private static final String uname = "root";
        private static final String pword = "root";

        public static void mwrite(Diary diary){

            String sql = "insert into diary VALUES(null,?,?,?,?)";

            Connection connection = null;
            PreparedStatement statement = null;
            SimpleDateFormat sim = new SimpleDateFormat("yyyy-MM-dd");


            try {
                //加载驱动
                Class.forName(driver);
                //获得数据库的链接
                connection = DriverManager.getConnection(url, uname, pword);
                //创建预编译的Statement
                statement = connection.prepareStatement(sql);
                //设置参数
                statement.setString(1,diary.getTitle());
                statement.setString(2,diary.getTab());
                statement.setString(3,sim.format(diary.getDate()));
                statement.setString(4,diary.getText());
                //执行
                statement.executeUpdate();
                System.out.println(sql);

            }catch (Exception e){
                e.printStackTrace();
            }finally {
                try{
                    if(statement != null){
                        statement.close();
                    }
                    if(connection != null){
                        connection.close();
                    }
                }catch (SQLException e){
                    e.printStackTrace();
                }
            }
        }

        public static Diary mysearch(String title) {

            String sql = "select * from diary where title = ?";
            Connection connection = null;
            PreparedStatement statement = null;
            ResultSet rs = null;
            Diary diary = new Diary();
            try{
                //加载驱动
                Class.forName(driver);
                //获得数据库的链接
                connection = DriverManager.getConnection(url, uname,pword);
                //预编译
                statement = connection.prepareStatement(sql);
                //赋值
                statement.setString(1,title);
                //执行
                rs = statement.executeQuery();
                if(rs.next()){

                    diary.setId(rs.getInt("id"));
                    diary.setTitle(rs.getString("title"));
                    diary.setTab(rs.getString("tab"));
                    diary.setDate(rs.getDate("date"));
                    diary.setText(rs.getString("text"));

                    return diary;
                }

            }catch (Exception e){
                e.printStackTrace();
            }finally {
                try {
                    if(statement != null){
                        statement.close();
                    }
                    if(connection != null){
                        connection.close();
                    }
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }

        public static List<Diary> myprint(String tab){

            String sql = "select * from diary where tab = ?";
            List<Diary> list = new ArrayList<Diary>();
            Connection connection = null;
            PreparedStatement statement = null;
            ResultSet rs = null;


            try{
                //加载驱动
                Class.forName(driver);
                //获得数据库的链接
                connection = DriverManager.getConnection(url, uname,pword);
                //预编译
                statement = connection.prepareStatement(sql);
                //赋值
                statement.setString(1,tab);
                // 执行
                rs = statement.executeQuery();
                while(rs.next()){

                    Diary diary = new Diary();

                    diary.setId(rs.getInt("id"));
                    diary.setTitle(rs.getString("title"));
                    diary.setTab(rs.getString("tab"));
                    diary.setDate(rs.getDate("date"));
                    diary.setText(rs.getString("text"));

                    list.add(diary);
                }
                return list;
            } catch (Exception e){
                e.printStackTrace();
            } finally {
                try {
                    if(statement != null){
                        statement.close();
                    }
                    if(connection != null){
                        connection.close();
                    }
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }

        //测试
        public static void main(String[] args) {
            String str = "2020-01-15";
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
            Date date = null;
            List<Diary> list = new ArrayList<Diary>();
            try {
                date = sdf.parse(str);
            } catch (ParseException e) {
                e.printStackTrace();
            }
            Diary diary = new Diary();
            diary.setTitle("水煮鱼");
            diary.setTab("美食");
            diary.setDate(date);
            diary.setText("水煮鱼，很可以，“油而不腻、辣而不燥、麻而不苦、肉质滑嫩”。");
            mwrite(diary);

            diary = mysearch("数据结构和算法");

//            String str1 = diary.toString();
//            System.out.println(str1);


            if(diary == null){
                System.out.println("no");
            }else {
                System.out.println(diary);
            }
//            list = myprint("学习");
            if(list == null || list.isEmpty()){
                System.out.println("no");
            } else {
                for (int i = 0; i < list.size(); i++) {
                    System.out.println(list.get(i));
                }
            }
        }

}
