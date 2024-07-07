select count(*) as FISH_COUNT
from fish_info fi
where (select fish_name from fish_name_info where fish_type = fi.fish_type) in ('BASS','SNAPPER');
