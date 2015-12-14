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

#include "queue_structure.h"
#include <stdlib.h>

void q_init(queue *q) {
	q->head = q->tail = NULL;
	q->size = 0;
}

int q_empty(queue *q) {
	return (q->size == 0);
}

int q_full(queue *q) {
	return 0;
}

int enqueue(queue *q, void *data) {
	qnode *new;
	new = (qnode *) malloc(sizeof(qnode));
	if(new == NULL) {
		return 0;
	}
	new->data = data;
	new->next = NULL;
	if(q->size == 0) {
		q->head = new;
	}
	else {
		q->tail->next = new;
	}
	q->tail = new;
	(q->size)++;
	return 1;
}

void *dequeue(queue *q) {
	qnode *tmp = q->head;
	void *info;
	q->head = q->head->next;
	if((q->size) == 1) {
		q->tail = NULL;
	}
	tmp->next = NULL;
	info = tmp->data;
	(q->size)--;
	free(tmp);
	return info;
}
