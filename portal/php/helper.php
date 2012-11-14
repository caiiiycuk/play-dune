<?php

function get_sort_column($key) {
	switch ($key) {
	    case 'harvested':
	        return 'harvested';
	    case 'destroyed':
	        return 'destroyed';
	    case 'killed':
	        return 'killed';
	}

	return 'score';
}

function get_sql_top($sort) {
	return 
"select 
	s.player player, coalesce(p.name, s.player) name, 
	s.house house, sum(s.killed) killed, sum(s.destroyed) destroyed, sum(s.harvested) harvested, 
	sum(s.score) score 
from 
	scores s 
left join 
	players p on p.player = s.player 
group by 
	s.player, s.house 
order by 
	sum(s.$sort) desc, s.player, s.house;";
}

function get_house($id) {
	switch ($id) {
		case 1:
			return 'atreides';
		case 2:
			return 'ordos';
	}

	return 'harkonnen';
}

?>