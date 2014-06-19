<?php

class views_filter_flag_filter extends views_handler_filter {

  function query() {
    $this->ensure_my_table();

    // make sure term node is joined in if needed
    // not exactly optimal since we may not need it if we're filtering by date
    $this->query->add_table('flagging');

//    $this->query->add_where($this->options['group'], "node.created > %s", strtotime('4 weeks ago'));

  }
}