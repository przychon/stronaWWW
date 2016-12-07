<?php

function fetchAllFoto($connectDB){
	$arrayFoto = array();

	$sqlQuery = "SELECT * FROM t_galeria";
	$sqlResult = mysqli_query($connectDB, $sqlQuery);
	$numRows = mysqli_num_rows($sqlResult);
	if($numRows > 0){
			while($oneFoto = mysqli_fetch_assoc($sqlResult)){
					$arrayFoto[] = $oneFoto;
			}
			return $arrayFoto;
	}else{
			return 0; // "Brak zdjęć w galerii";
	}
};

function getOnePhoto($connectDB, $id_foto){
	$sqlQuery = "SELECT tytul_foto, nazwaPliku_foto FROM t_galeria WHERE id_foto =" . $id_foto;
	//echo $sqlQuery;
	$sqlResult = mysqli_query($connectDB, $sqlQuery);
	$numRows = mysqli_num_rows($sqlResult);
	if($numRows > 0){
			//$oneFoto =  //pobranie rekordu jednego zdjecia w postaci tablicy asocjacyjnej
					//return $oneFoto; //tablica z jednym zdjeciem
					return mysqli_fetch_assoc($sqlResult);
	}else{
			return 0; //brak zdjec
	}
};

//USUWANIE ZDJECIA
function usunFoto($connectDB,$id_foto,$nazwaPliku_foto){
	$sqlQuery = "DELETE FROM t_galeria WHERE id_foto = $id_foto";
	//echo $sqlQuery;
	mysqli_query($connectDB, $sqlQuery);
	unlink($nazwaPliku_foto);
	//debug($dataFileNew);

	header("Location: index.php"); //zeby po usunieciu przenioslo mnie na główna strone
};


//DODWANIE FOTO NA SERWER
function addNewFoto($connectDB, $dataFormNew, $dataFileNew){ //dodawanie nowego zdjecia
	if($dataFileNew["nazwaPliku_foto"]["type"]=="image/jpeg"){
	//debug($dataFormNew);
	//debug($dataFileNew);
	if(is_uploaded_file($dataFileNew["nazwaPliku_foto"]["tmp_name"])== true){
		//$dataFileNew["nazwaPliku_foto"]["tmp_name"];
		$test = move_uploaded_file($dataFileNew["nazwaPliku_foto"]["tmp_name"], "img/".$dataFileNew["nazwaPliku_foto"]["name"]);
		//debug($test);
		if($test == true){
				$sqlQuery = "INSERT INTO t_galeria (tytul_foto, nazwaPliku_foto) VALUES ('".$dataFormNew['tytul_foto']."','"."img/".$dataFileNew['nazwaPliku_foto']['name']."')";

				mysqli_query($connectDB, $sqlQuery);
		}
	}
}else{
	echo "Tylko pliki .jpg!";
}
};

//AKTUALIZUJ ZDJECIE
function aktualizujFoto($connectDB, $id_foto){
	$sqlQuery = "SELECT * FROM t_galeria WHERE id_foto = $id_foto";
	$sqlResult = mysqli_query($connectDB, $sqlQuery);
	$numRows = mysqli_num_rows($sqlResult);
	if($numRows > 0){
			return mysqli_fetch_assoc($sqlResult);
	}else{
			return 0;
	}
};

//I ZAPISZ ZAKTUALIZOWANĄ
function saveNewFoto($connectDB, $dataFormNew, $dataFileNew){
	if($dataFileNew["nazwaPliku_foto"]["type"]=="image/jpeg"){
	if(is_uploaded_file($dataFileNew["nazwaPliku_foto"]["tmp_name"])== true){
		$test = move_uploaded_file($dataFileNew["nazwaPliku_foto"]["tmp_name"], "img/".$dataFileNew["nazwaPliku_foto"]["name"]);
		if($test == true){
			$sqlQuery="UPDATE t_galeria SET
				tytul_foto = '".$dataFormNew["tytul_foto"]."',
				nazwaPliku_foto='img/".$dataFileNew["nazwaPliku_foto"]["name"]."'
				WHERE id_foto = ".$_GET["id_foto"];
	//echo $sqlQuery;
	//debug($dataFormNew);
	//debug($dataFileNew);
	//debug($_GET);
			mysqli_query($connectDB, $sqlQuery);

			//Usuwam plik z folderu (jeśli nowy plik nie nazywa sie tak samo jak plik pierwotny) to by moglo byc jakos w ifie!
			if("img/".$dataFileNew["nazwaPliku_foto"]["name"] != $dataFormNew["nazwaPliku_fotoOld"]){
				unlink($dataFormNew["nazwaPliku_fotoOld"]);
			}
		}

		}else{
			$sqlQuery="UPDATE t_galeria SET
			tytul_foto = '".$dataFormNew["tytul_foto"]."'
			WHERE id_foto = ".$_GET["id_foto"];

			mysqli_query($connectDB, $sqlQuery);
		}

}else{
	echo "Tylko pliki .jpg!";
}
};



 ?>
