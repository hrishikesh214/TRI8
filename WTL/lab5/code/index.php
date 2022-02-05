<?php
    require('./connection.php');

    $tasks = $db->query('select * from tasks');
    // debug($tasks->fetch_all(MYSQLI_ASSOC)); die();
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
       <h1>Add New Task</h1>
       <div class="add-form">
           <form class="form" action="add_task.php" method="post">
               <input class="action" type="text" name="action" placeholder="Action">
               <br>
               <textarea class="description" placeholder="description" name="description"></textarea>
               <br>
               <input class="remind-at" type="datetime-local" name="remind_at">
               <br> 
               <input class="submit-btn" type="submit" name="submit" value="Add">
           </form>
       </div>
       <div class="error">
           <spam class="msg">
                <?=isset($_GET['error'])? '<b>Error: </b>'.$_GET['error']: ''?>
            </spam>
       </div>
    </section>
    <section class="todo-container">
        <div class="tasks">
            <h1>Tasks</h1>
            <?php foreach ($tasks as $task) : ?>
                <div class="task">
                    <div class="action">
                        <?=$task['action']?>
                        <button class="done-btn" onclick="redirect(<?=$task['id']?>)">Done</button>
                        <button class="done-btn" onclick="update_page(<?=$task['id']?>)">Update</button>
                    </div> 
                    <div class="description"><?=$task['description']?></div>
                    <div class="time">at <?=$task['remind_at']?></div>
                </div>
            <?php endforeach; ?>
        </div>
        <script type="text/javascript">
            function redirect(tid){
                window.location.href='<?=$base_url?>' + `/delete_task.php?task_id=${tid}`
            }
            function update_page(tid){
                window.location.href='<?=$base_url?>' + `/update_task.php?task_id=${tid}`
            }
        </script>
    </section>
</body>
</html>