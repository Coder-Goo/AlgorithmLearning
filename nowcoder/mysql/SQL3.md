查取当前薪水详情以及部门编号dept_no

如何查取一个部门的所有信息 :  s.*

    select s.* ,d.dept_no
    from salaries s
    join dept_manager d
    ON s.emp_no = d.emp_no
    order by emp_no;
