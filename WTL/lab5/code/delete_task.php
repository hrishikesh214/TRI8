<?php
	require './connection.php';
	// debug($_GET);
	if(isset($_GET['task_id'])){
		$task_id = $_GET['task_id'];

		$sql = 'delete from tasks where id = '.$task_id;
		// debug($sql); die();
		$res = $db->query($sql);
		if($res){
			header('location: http://localhost/WTL/lab5');
		}
		else{
			echo "ERROR DELETING TASK";
		}
	}