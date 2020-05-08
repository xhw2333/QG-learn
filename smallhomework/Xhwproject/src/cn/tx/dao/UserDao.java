package cn.tx.dao;


import cn.tx.model.Ueser;
import com.mysql.cj.xdevapi.PreparableStatement;

import java.sql.*;

public class UserDao {

    private static final String driver = "com.mysql.cj.jdbc.Driver";
    private static final String url = "jdbc:mysql://localhost:3306/myku?characterEncoding=utf-8&serverTimezone=GMT%2B8";
    private static final String uname = "root";
    private static final String pword = "root";

    public static void insert(Ueser user){

        String sql = "insert into ueser VALUES(null,?,?,?)";

        Connection connection = null;
        PreparedStatement statement = null;
        try{
            //加载驱动
            Class.forName(driver);
            //获得数据库的链接
            connection = DriverManager.getConnection(url, uname,pword);
            //创建预编译的Statement
            statement = connection.prepareStatement(sql);
            //设置参数
            statement.setString(1,user.getUsername());
            statement.setString(2,user.getPassword());
            statement.setString(3,user.getPhone());
            /*
            statement.setDate(4,new java sql.Date(user.getBirth(),getTime());
            */
            //执行
            statement.executeUpdate();
            System.out.println(sql);

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
    }

    public static int check(String username, String password){

        String sql = "select * from ueser where username = ? and password = ?";
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
            //给？设值
            statement.setString(1,username);
            statement.setString(2,password);
            //执行sql语句
            rs = statement.executeQuery();
            if(rs.next()){
                return 1;
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
        return  0;
    }

    public Ueser login(Ueser loginUser){

        return null;
    }

    //测试
    public static void main(String[] args) {
        int num = 6;
        Ueser user = new Ueser();
        user.setUsername("xhw");
        user.setPassword("123");
        user.setPhone("123453678");
        insert(user);
        num = check("hhh", "1234");
        System.out.println(num);
    }

}