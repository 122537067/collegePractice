package dao;

import dao.DbHelper;

public class BaseDao {
	
	private String driver = "com.mysql.jdbc.Driver";
	private String url = "jdbc:mysql://localhost:3306/sms";
	private String user = "root";
	private String pwd = "123456";
	
	private DbHelper db;
	public BaseDao(){
		String driver = "com.mysql.jdbc.Driver";
		String url = "jdbc:mysql://localhost:3306/sms";
		String user = "root";
		String pwd = "123456";
		this.db = new DbHelper(driver,url,user,pwd);
	}

	/**public BaseDao(HttpServletRequest request){

		this.driver = request.getSession().getServletContext().getInitParameter("database_driver");
		this.url = request.getSession().getServletContext().getInitParameter("database_url");
		this.user = request.getSession().getServletContext().getInitParameter("database_user");
		this.pwd = request.getSession().getServletContext().getInitParameter("database_pwd");
	}**/
	
	public DbHelper createDbHelper(){
		return new DbHelper(driver,url,user,pwd);
	}
	
	public String getDriver() {
		return driver;
	}
	public void setDriver(String driver) {
		this.driver = driver;
	}
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}
	public String getUser() {
		return user;
	}
	public void setUser(String user) {
		this.user = user;
	}
	public String getPwd() {
		return pwd;
	}
	public void setPwd(String pwd) {
		this.pwd = pwd;
	}
}
