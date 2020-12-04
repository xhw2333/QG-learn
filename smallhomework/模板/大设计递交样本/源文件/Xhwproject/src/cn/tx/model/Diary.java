package cn.tx.model;


import java.util.Date;

public class Diary {

    private int id;

    private String title;

    private String tab;

    private String text;

    private Date date;

    public Diary() {
    }

    public Diary(int id, String title, String tab, String text, Date date) {
        this.id = id;
        this.title = title;
        this.tab = tab;
        this.text = text;
        this.date = date;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTab() {
        return tab;
    }

    public void setTab(String tab) {
        this.tab = tab;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return "Diary = {" +
                "id:" + id +
                ", title:'" + title + '\'' +
                ", tab:'" + tab + '\'' +
                ", date:'" + date + '\'' +
                ", text:'" + text + '\'' +
                "}";
    }
}
