/*  Copyright 2015 :
	Vaibhav Kurhe <vaibhav.kurhe@gmail.com>
	Abhilash Mhaisne <55abhilash@openmailbox.org>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "stack_structure.h"
#include <stdlib.h>

void s_init(stack *s) {
	s->top = NULL;
	s->size = 0;
}

int s_empty(stack *s) {
	return (s->size == 0);
}

int s_full(stack *s) {
	return 0;
}

int push(stack *s, void *data) {
	snode *new;
	new = (snode *) malloc(sizeof(snode));
	if(new == NULL) {
		return 0;
	}
	new->data = data;
	new->up = new->down = NULL;
	if(!s_empty(s)) {
		s->top->up = new;
		new->down = s->top;
	}
	s->top = new;
	s->size++;
	return 1;
}

void *pop(stack *s) {
	snode *tmp;
	void *info;
	tmp = s->top;
	info = tmp->data;
	s->top = s->top->down;
	if(s->size > 1) {
		s->top->up = NULL;
	}
	tmp->down = NULL;
	(s->size)--;
	free(tmp);
	return info;
}
