       {
                if (ptr2->data == ptr3->data)
                {
                    ptr2->next = ptr3->next;
                }
                else{
                    ptr2=ptr2->next;
                    ptr3=ptr3->next;
                }
            }