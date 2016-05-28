/*удаление тригеров "на удаление" */
drop trigger save_id on plan;
drop function save_id_plan();

drop trigger save_id on topic;
drop function save_id_topic();

drop trigger save_id on skb;
drop function save_id_skb();

drop trigger save_id on executive;
drop function save_id_executive();

/*удаление тригеров "на добавление" */
drop trigger look_id on plan;
drop function look_id_plan();

drop trigger look_id on topic;
drop  function look_id_topic();

drop trigger look_id on skb;
drop  function look_id_skb();

drop trigger look_id on executive;
drop  function look_id_executive();

/*удаление таблиц базы данных*/
drop table topic;

drop table plan;
 
drop table skb;

drop table executive;

drop table plan_id;

drop table topic_id;

drop table skb_id;

drop table executive_id;

