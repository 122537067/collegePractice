package com.cduestc.crud.test;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;
import org.mybatis.generator.api.MyBatisGenerator;
import org.mybatis.generator.config.Configuration;
import org.mybatis.generator.config.xml.ConfigurationParser;
import org.mybatis.generator.internal.DefaultShellCallback;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.cduestc.crud.bean.Department;
import com.cduestc.crud.bean.Employee;
import com.cduestc.crud.dao.DepartmentMapper;
import com.cduestc.crud.dao.EmployeeMapper;


//@RunWith(SpringJUnit4ClassRunner.class)
//@ContextConfiguration(locations={"classpath://applicationContext.xml"})//
public class MybatisTestPlus {
	
	
	@Autowired
	DepartmentMapper departmentMapper;
	
	
	
	public SqlSessionFactory getSqlSessionFactory() throws IOException{
		String resource = "mybatis-config.xml";
		InputStream inputStream = Resources.getResourceAsStream(resource);
		SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
		return sqlSessionFactory;
	}
	
	@Test
	public void testMbg() throws Exception {
		List<String> warnings = new ArrayList<String>();
		boolean overwrite = true;
		File configFile = new File("mbg.xml");
		ConfigurationParser cp = new ConfigurationParser(warnings);
		Configuration config = cp.parseConfiguration(configFile);
		DefaultShellCallback callback = new DefaultShellCallback(overwrite);
		MyBatisGenerator myBatisGenerator = new MyBatisGenerator(config,
				callback, warnings);
		myBatisGenerator.generate(null);
	}
	
	@Test
	public void testCRUD(){
//		????SpringIOC????
		ApplicationContext ioc = new ClassPathXmlApplicationContext("applicationContext.xml");
//		???????§Ý??mapper
		DepartmentMapper departmentMapper =  ioc.getBean(DepartmentMapper.class);
		EmployeeMapper employeeMapper = ioc.getBean(EmployeeMapper.class);
		System.out.println(employeeMapper);
		System.out.println(departmentMapper);
//		??????????????
		departmentMapper.insert(new Department(null,"?????"));
		departmentMapper.insert(new Department(null,"??????"));
		employeeMapper.insert(new Employee(null,"Jerry", "1", "Jerry@qq.com", 2));
		
	}
	@Test
	public void testCRUD2(){
//		????SpringIOC????
		ApplicationContext ioc = new ClassPathXmlApplicationContext("applicationContext.xml");
//		???????§Ý??mapper
		EmployeeMapper employeeMapper = ioc.getBean(EmployeeMapper.class);
		System.out.println(employeeMapper);

		employeeMapper.insert(new Employee(null,"Jerry", "1", "Jerry@qq.com", 2));
		
	}
	
	
}
