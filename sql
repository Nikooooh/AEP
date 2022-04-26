public function listarEstilos(){
  $conn = Connection::getInstance()->connection;
  $sql = 'SELECT distinct estilo.* from estilo inner join album using (cod_estilo) order by estilo';
  $query = $conn->query($sql);
  $results = $query->fetchAll;
  return $results;
 }
}
