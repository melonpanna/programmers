SELECT food_type, rest_id, rest_name, favorites
from rest_info r
where favorites = (select max(favorites) from rest_info group by food_type having food_type = r.food_type)
order by food_type desc;