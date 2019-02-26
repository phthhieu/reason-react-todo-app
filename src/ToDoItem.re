let component = ReasonReact.statelessComponent("ToDoItem");

let make = (~title, _children) => {
  ...component,
  render: _self =>
    <li>
      <div className="view">
        <label> {ReasonReact.string(title)} </label>
      </div>
    </li>,
};
