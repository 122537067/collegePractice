package ClassInfo;

import javax.servlet.http.HttpServletRequest;

import ClassInfo.DbHelper;

public class BaseDao {
	
	private String driver = null;
	private String url = null;
	private String user = null;
	private String pwd = null;
	
	public BaseDao(String driver,String url,String user,String pwd){
		this.driver = driver;
		this.url = url;
		this.user = user;
		this.pwd = pwd;
	}

	public BaseDao(HttpServletRequest request){

		this.driver = request.getSession().getServletContext().getInitParameter("database_driver");
		this.url = request.getSession().getServletContext().getInitParameter("database_url");
		this.user = request.getSession().getServletContext().getInitParameter("database_user");
		this.pwd = request.getSession().getServletContext().getInitParameter("database_pwd");
	}
	
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
