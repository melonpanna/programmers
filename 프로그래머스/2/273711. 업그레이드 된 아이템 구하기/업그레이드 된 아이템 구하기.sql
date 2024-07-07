select t1.item_id, t1.item_name, t1.rarity
from item_info t1
where 
(select rarity from item_info t3 where t3.item_id = (select parent_item_id from item_tree where item_id = t1.item_id)) = 'RARE'
order by t1.item_id desc;
