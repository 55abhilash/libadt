/*  Copyright 2015 :
	Vaibhav Kurhe <kurhe.vaibhav@gmail.com>
	Abhilash Mhaisne <55abhilash@openmailbox.org>
    This program is a part of libadt : you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
typedef struct qnode {
	void *data;
	struct qnode *next;
} qnode;

typedef struct queue {
	qnode *head;
	qnode *tail;
	int size;
} queue;

void q_init(queue *q);
int q_empty(queue *q);
int q_full(queue *q);
int enqueue(queue *q, void *data);
void *dequeue(queue *q);
