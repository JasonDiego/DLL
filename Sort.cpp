void DoublyLinkedList::sort() {

	bool listSorted = false;
	Node* n1; Node* n2;

	if (head == nullptr || head->next == nullptr) return;

	// Loop 'A' will continue looping as long as list remains unordered
	while (!listSorted) {
		listSorted = true;
		n1 = head;
		n2 = head->next;

		// Loop 'B' will traverse through the list once, sorting any adjacent elements that may be out of order
		while (n2 != nullptr) {

			if (n1->value > n2->value) {

				listSorted = false;

				if (n1->previous == nullptr) { // [X] [Y] [] []

					head = n2;

					n2->previous = nullptr;
					n1->next = n2->next;
					n2->next = n1;
					n1->previous = n2;
					n1->next->previous = n1;

					n1 = n2;
					n2 = n2->next;
				}
				else if (n2 != tail) { // [] [X] [Y] []

					n1->previous->next = n2;
					n2->previous = n1->previous;
					n1->next = n2->next;
					n1->previous = n2;
					n1->next->previous = n1;
					n2->next = n1;

					n1 = n2;
					n2 = n2->next;
				}
				else { // else if [] [] [x] [y]

					tail = n1;

					n1->previous->next = n2;
					n2->previous = n1->previous;
					n1->next = nullptr;
					n1->previous = n2;
					n2->next = n1;

					n1 = n2;
					n2 = n2->next;
				}
			}
			else { // current nodes adjacent to each other are in order
				n1 = n1->next;
				n2 = n2->next;
			}
		}
	}
}
