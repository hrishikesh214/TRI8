<?php
	require './connection.php';
	// debug($_POST); die();
	// $_REQUEST[];
	if(isset($_POST['submit'])){
		$data = [
			'action' => $_POST['action'],
			'description' => $_POST['description'],
			'remind_at' => $_POST['remind_at']
		];
		// debug($data); die();

		# validation
		$is_error = false;
		$where_error = [];

		foreach ($data as $key => $value) {
			if($value == ''){
				$is_error = true;
				$where_error[] = $key;
			}
		}

		if($is_error){
			$error_str = '';
			foreach ($where_error as $e) {
				$error_str = $error_str . $e . ', ';
			}
			$error_str = substr($error_str, 0, -2 );
			$error_str .= ' is required';
			header('location: http://localhost/WTL/lab5/?error='.$error_str);
			die('ERROR');
		}


		$sql = 'insert into tasks (action, description, remind_at) values ("'.$data["action"].'", "'.$data["description"].'", "'.$data["remind_at"].'")';
		// debug($sql);die();
		$res = $db->query($sql);
		// debug($res); die();
		if($res){
			header('location: http://localhost/WTL/lab5');
		}
		else{
			echo "ERROR IN ADDING TASK";
		}
	}