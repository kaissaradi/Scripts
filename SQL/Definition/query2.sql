-- write your queries to insert data here
--insert into client table
insert into client (first_name, last_name, dob) 
values ('Sara', 'Smith', '1970-01-02');

insert into client (first_name, last_name, dob) 
values ('Miguel', 'Cabrera', '1988-02-02');

insert into client (first_name, last_name, dob) 
values ('Bo', 'Chang', '1985-03-02');
--insert into employee table
insert into employee (first_name, last_name, dob, date_joined) 
values ('Ananya', 'Jaiswal', '1975-01-02', '2009-01-01');

insert into employee (first_name, last_name, dob, date_joined) 
values ('Michael', 'Fern', '1980-10-18', '2013-06-05');

insert into employee (first_name, last_name, dob, date_joined) 
values ('Abdul', 'Rehman', '1984-03-21', '2013-11-10');
--insert into project
insert into project (cid, name, notes) 
values (select id from client where first_name = 'Sara' and last_name = 'Smith', 
	'Diamond', 
	'Should be done by Jan 2019');

insert into project (cid, name, notes) 
values (select id from client where first_name = 'Sara' and last_name = 'Smith', 
	'Diamond', 
	'Should be done by Jan 2019');

insert into project (cid, name, notes) 
values (select id from client where first_name = 'Bo' and last_name = 'Chang', 
	'Chan\'g', 
	'Ongoing maintenance');

insert into project (cid, name, notes) 
values (select id from client where first_name = 'Miguel' and last_name = 'Cabrera', 
	'The Robinson Project', 
	NULL);
--insert into works on table
insert into works_on (eid, pid, start_date) 
values (select id from employee where first_name = 'Ananya' and last_name = 'Jaiswal', 
	select pid from project where name = 'Chang\'g', 
	'2012-01-01');

insert into works_on (eid, pid, start_date) 
values (select id from employee where first_name = 'Michael' and last_name = 'Fern', 
	select pid from project where name = 'The Robinson Project', 
	'2013-08-08');

insert into works_on (eid, pid, start_date) 
values (select id from employee where first_name = 'Abdul' and last_name = 'Rehman', 
	select pid from project where name = 'Diamond', 
	'2014-09-11');

-- Leave the queries below untouched. These are to test your submission correctly.
select * from project;
select * from client;
select * from employee;
select * from works_on;
