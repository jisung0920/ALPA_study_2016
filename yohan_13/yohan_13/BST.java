package BST;
public class BST {
	private Node root;
	
	private class Node{
		private int key;
		private Node left_child;
		private Node right_child;
		private Node parent;
		Node(int key){
			this.key = key;
		}
	}
	
	public void insert(int key){
		if(this.search(key) != null){
			System.out.println(key + " is already in the tree");
			return;
		}
		Node newNode = new Node(key);	// assume the data is same as key
		//////////////////////////////////// todo
		if(root == null){
			root = newNode;
		}else{
			Node current = root;
			Node parent = current;
			while(true){
				parent = current;
				if(newNode.key<current.key){
				current = current.left_child;
				if(current == null){
					parent.left_child = newNode;
					return;
				}
			}else{
				current= current.right_child;
				if(current == null){
					parent.right_child = newNode;
					return;
					}
				}
			}
		}
	}
	public void delete(int key){
		//////////////////////////////////// todo
		 	Node current = root;
	        Node parent = current;

	        while(current.key != key){
	            if (current == null)        // Ű ���� ���� ��� ����
	            	return;
	            parent = current;
	            if (key < current.key)
	                current = current.left_child;
	            else
	                current = current.right_child;
	        }

	        // �ڽ��� ���� ��
	        if (current.left_child == null && current.right_child == null)
	        {
	            if (current == root)        // Ʈ�� ����
	                root = null;
	            else if (current == parent.left_child)
	                parent.left_child = null;
	            else
	                parent.right_child = null;
	        }

	        // �ڽ��� �ϳ��� ��
	        else if (current.right_child == null)        // �����ڽĸ� ����
	        {
	            if (current == root)
	                root = current.left_child;
	            else if (current == parent.left_child)
	                parent.left_child = current.left_child;
	            else
	                parent.right_child = current.left_child;
	        }

	        else if (current.left_child == null)            // �������ڽĸ� ����
	        {
	            if (current == root)
	                root = current.right_child;
	            else if (current == parent.left_child)
	                parent.left_child = current.right_child;
	            else
	                parent.right_child = current.right_child;
	        }

	        // �ڽ��� ���� ��
	        else{
	            // ��������� �ĺ���� ã��
	            Node candidate = getCandidate(current);

	            if (current == root)
	                root = candidate;
	            else if (current == parent.left_child)
	                parent.left_child = candidate;
	            else
	                parent.right_child = candidate;
	            
	            candidate.right_child = current.right_child;
	        }
	}
	
	private Node getCandidate(Node deleteNode)
    {
        Node candidateParent = deleteNode;
        Node candidate = candidateParent.left_child;

        // ������� ������ �ڽ��� ���� �ڼ� ã��
        while (candidate.right_child != null){
            candidateParent = candidate;
            candidate = candidate.right_child;
        }
        
        if (candidate != deleteNode.left_child)
        {
            candidateParent.right_child = candidate.left_child;
            candidate.left_child = deleteNode.left_child;
        }

        return candidate;
    }
	public Node search(int key){
		/////////////////////////// todo
		Node current = root;
		
		while(current!=null){
			if(current.key == key)
				return current;
			else if(key<current.key)
				current = current.left_child;
			else
				current = current.right_child;
			}
			return current;
		}
	
	public void printPreorder(Node node){
		
		if (node != null){
			System.out.printf("%d ",node.key);
            printPreorder(node.left_child);
            printPreorder(node.right_child);
        }
		
	}
	public void printInorder(Node node){
		if (node != null){
            printInorder(node.left_child);
            System.out.printf("%d ",node.key);	
            printInorder(node.right_child);
        }
	}
	public void printPostorder(Node node){
	
		 if (node != null){
	            printPostorder(node.left_child);
	            printPostorder(node.right_child);
	            System.out.printf("%d ",node.key);
	        }
	}
	public Node getRoot(){
		return root;
	}
}
