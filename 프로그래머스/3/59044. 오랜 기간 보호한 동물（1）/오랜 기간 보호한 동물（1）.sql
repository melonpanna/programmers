SELECT ai.name, ai.datetime
from animal_ins ai
left join animal_outs ao
on ai.animal_id = ao.animal_id
where sex_upon_outcome is null
order by datetime asc limit 3;