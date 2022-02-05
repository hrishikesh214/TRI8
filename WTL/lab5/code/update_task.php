<?php
	require './connection.php';

	if(isset($_REQUEST['submit'])){
		debug($_REQUEST);
		$data = [
			'id' => $_REQUEST['task_id'],
			'action' => $_REQUEST['action'],
			'description' => $_REQUEST['description'],
			'remind_at' => $_REQUEST['remind_at']
		];

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

		$sql = 'update tasks set action = "'.$data['action'].'", description = "'.$data['description'].'", remind_at = "'.$data['remind_at'].'" where id = '.$data['id'];
		debug($sql);
		$res = $db->query($sql);
		// debug($res);
		if($res){
			header('location: http://localhost/WTL/lab5');
		}
		else{
			echo "ERROR IN UPDATING TASK";
		}
		exit(0);
	}


	// debug($_GET);
	if(isset($_GET['task_id'])){
		$task_id = $_GET['task_id'];

		$sql = 'select * from tasks where id = '.$task_id;
		// debug($sql);
		$res = $db->query($sql);
		
		if($res->num_rows < 1){
			$error_str = 'Task not found!';
			header('location: http://localhost/WTL/lab5/?error='.$error_str);
			die('TASK NOT FOUND!');
		}
		$task = $res->fetch_assoc();
	}

?>


<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>TODO</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <section class="form-container">
       <h2>Update Task (ID: <?=$task['id']?>)</h2>
       <div class="add-form">
           <form class="form" action="" method="post">
               <input 
	               class="action" 
	               type="text" 
	               name="action" 
	               placeholder="Action" 
	               value="<?=$task['action']?>"
               >
               <br>
               <textarea 
	               class="description" 
	               placeholder="description" 
	               name="description"><?=$task['description']?></textarea>
               <br>
               <input 
	               class="remind-at" 
	               type="datetime-local" 
	               name="remind_at"
	               value="<?=$task['remind_at']?>"
               >
               <br> 
               <input class="submit-btn" type="submit" name="submit" value="Update">
           </form>
       </div>
       <div class="error">
           <spam class="msg">
                <?=isset($_GET['error'])? '<b>Error: </b>'.$_GET['error']: ''?>
            </spam>
       </div>
    </section>
    
        <script type="text/javascript">

        </script>
    </section>
</body>
</html>