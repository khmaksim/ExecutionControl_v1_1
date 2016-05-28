/*создание таблиц базы данных*/
create table executive
(
	id_executive		integer,
	surname				varchar(20),
	name				varchar(20),
	patronymic			varchar(20),
	phone				varchar(15),
	cabinet				varchar(5),
	constraint			executive_pk primary key(id_executive)
);

create table skb
(
	id_skb				integer,
	name_skb			varchar(100),
	constraint			skb_pk primary key(id_skb)
);

create table plan
(
	id_plan				integer,
	name_plan			varchar(200),
	constraint			plan_pk	primary key(id_plan)
);

create table topic
(
	id_topic			integer,
	id_plan 			integer,
	name_topic			varchar(400),
	id_skb				integer,
	id_executive 		integer,
	date_execution		date,
	stamp				varchar(100),
	constraint			topic_pk primary key(id_topic),
	constraint			topic_plan_fk foreign key(id_plan) references plan(id_plan),
	constraint			topic_skb_fk foreign key(id_skb) references skb(id_skb),
	constraint			topic_executive_fk foreign key(id_executive) references executive(id_executive)
);

create table plan_id
(
	id					integer
);

create table topic_id
(
	id					integer
);

create table skb_id
(
	id					integer
);

create table executive_id
(
	id					integer
);
/*создание тригеров "на удаление"*/
create or replace function save_id_plan() returns trigger as '
declare
	save_id integer;
begin
	select into save_id id_plan from plan where id_plan = old.id_plan;
	insert into plan_id values(save_id);
	return old;
end;
' language 'plpgsql';
create trigger save_id before delete on plan for each row execute procedure save_id_plan();

create or replace function save_id_topic() returns trigger as '
declare
	save_id integer;
begin
	select into save_id id_topic from topic where id_topic = old.id_topic;
	insert into topic_id values(save_id);
	return old;
end;
' language 'plpgsql';
create trigger save_id before delete on topic for each row execute procedure save_id_topic();

create or replace function save_id_skb() returns trigger as '
declare
	save_id integer;
begin
	select into save_id id_skb from skb where id_skb = old.id_skb;
	insert into skb_id values(save_id);
	return old;
end;
' language 'plpgsql';
create trigger save_id before delete on skb for each row execute procedure save_id_skb();

create or replace function save_id_executive() returns trigger as '
declare
	save_id integer;
begin
	select into save_id id_executive from executive where id_executive = old.id_executive;
	insert into executive_id values(save_id);
	return old;
end;
' language 'plpgsql';
create trigger save_id before delete on executive for each row execute procedure save_id_executive();

/*создание тригеров "на добавление"*/
create or replace function look_id_plan() returns trigger as '
declare
	min_id integer;
	new_id integer;
begin
	select into min_id min(id) from plan_id;
	if min_id is null then
		select into min_id max(id_plan) from plan;
		if min_id is null then
			min_id := 0;
		else
			min_id := min_id + 1;
		end if;
	end if;
	new_id := min_id;
	new.id_plan := new_id;
	delete from plan_id where id = new_id;
	return new;
end;
' language 'plpgsql';

create trigger look_id before insert on plan for each row execute procedure look_id_plan();

create or replace function look_id_topic() returns trigger as '
declare
	min_id integer;
	new_id integer;
begin
	select into min_id min(id) from topic_id;
	if min_id is null then
		select into min_id max(id_topic) from topic;
		if min_id is null then
			min_id := 0;
		else
			min_id := min_id + 1;
		end if;
	end if;
	new_id := min_id;
	new.id_topic := new_id;
	delete from topic_id where id = new_id;
	return new;
end;
' language 'plpgsql';

create trigger look_id before insert on topic for each row execute procedure look_id_topic();

create or replace function look_id_skb() returns trigger as '
declare
	min_id integer;
	new_id integer;
begin
	select into min_id min(id) from skb_id;
	if min_id is null then
		select into min_id max(id_skb) from skb;
		if min_id is null then
			min_id := 0;
		else
			min_id := min_id + 1;
		end if;
	end if;
	new_id := min_id;
	new.id_skb := new_id;
	delete from skb_id where id = new_id;
	return new;
end;
' language 'plpgsql';

create trigger look_id before insert on skb for each row execute procedure look_id_skb();

create or replace function look_id_executive() returns trigger as '
declare
	min_id integer;
	new_id integer;
begin
	select into min_id min(id) from executive_id;
	if min_id is null then
		select into min_id max(id_executive) from executive;
		if min_id is null then
			min_id := 0;
		else
			min_id := min_id + 1;
		end if;
	end if;
	new_id := min_id;
	new.id_executive := new_id;
	delete from executive_id where id = new_id;
	return new;
end;
' language 'plpgsql';

create trigger look_id before insert on executive for each row execute procedure look_id_executive();